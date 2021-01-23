#include "Picture.h"
#include"cstring"

PgmPicture::PgmPicture(int w,int h,RGB c) : width(w), height(h)
{
 
  pixels.resize(width*height);
  for(int i=0;i<pixels.size();i++)
      pixels[i] = c ;
}

void PgmPicture::save(const string &name) const 
{
  ofstream os(name+".pgm");

  os << "P3" << endl;
  os << "# " << name << " created by TP4" << endl;
  os << width << " " << height << endl;
  os << "255" << endl;

  for(int i=0;i<height;i++)
  {
    for(int j=0;j<width;j++)
    {
      os << pixels[i*width+j].r << " " <<  pixels[i*width+j].g << " " <<  pixels[i*width+j].b  << "  ";
    }
    os << endl;
  }
}


void PgmPicture::load(const string &name)
{
  ifstream is(name+".pgm");

  if(!is)
  {
    cerr << "the file : " << name << ".pgm do not exist" << endl;
  }

  string temp ;
  string format ;
  
  getline(is,format);  // read P2/P3
  getline(is,temp);  // read # ...

  is >> width >> height;
  is >> temp;

  pixels.resize(width*height);
  if(format=="P2")
  {
    int grey ;
    for(int i=0;i<height;i++)
    {
      for(int j=0;j<width;j++)
      {
        is >> grey ; 
        pixels[i*width+j] = RGB(grey,grey,grey) ;
      }
    }
  }
  else if(format=="P3")
  {
    RGB color ; 
    for(int i=0;i<height;i++)
    {
      for(int j=0;j<width;j++)
      {
        is >> color.r >> color.g >> color.b ; 
        pixels[i*width+j] = color ;
      }
    }
  }
  else
  {
    cerr << "unkown PGM format : " << format << endl; 
  }
  
}

// -------------------------------------------

#pragma pack(1)  // desative l'alignement mémoire
typedef int int32;
typedef short int16;

struct BMPImHead
{
	int32 size_imhead;
	int32 width;
	int32 height;
	int16 nbplans; // toujours 1
	int16 bpp;
	int32 compression;
	int32 sizeim;
	int32 hres;
	int32 vres;
	int32 cpalette;
	int32 cIpalette;
};

struct BMPHead
{
	char signature[2];
	int32 taille;
	int32 rsv;
	int32 offsetim;
	struct BMPImHead imhead;
};


void PgmPicture::saveBMP(const string & name) const
{
  string file=name+".bmp";
	struct BMPHead head;
	int i,j,tailledata,pitch;
	unsigned char bgrpix[3];
	char corrpitch[4] = {0,3,2,1};
	FILE* F = fopen(file.c_str(),"wb");
	if (!F)
	{
          cout << "error : file " << file << " do not exist" << endl;
          exit(-1);
        }

	memset(&head,0,sizeof(struct BMPHead));
	head.signature[0] = 'B';
	head.signature[1] = 'M';
	head.offsetim = sizeof(struct BMPHead); // je vais toujours écrire sur le même moule.
	head.imhead.size_imhead = sizeof(struct BMPImHead);
	head.imhead.width = width;
	head.imhead.height = height;
	head.imhead.nbplans = 1;
	head.imhead.bpp = 24;
	pitch = corrpitch[(3*head.imhead.width)%4];
	tailledata = 3*head.imhead.height*head.imhead.width + head.imhead.height*pitch;
	head.imhead.sizeim = tailledata;
	head.taille = head.offsetim + head.imhead.sizeim;
	fwrite(&head,sizeof(struct BMPHead),1,F);
	for(j=height-1;j>=0;j--)
	{
		for(i=0;i<width;i++)
		{
			bgrpix[0] = pixels[j*width+i].b;
			bgrpix[1] = pixels[j*width+i].g;
			bgrpix[2] = pixels[j*width+i].r;
			fwrite(&bgrpix,1,3,F);
		}
		bgrpix[0] = bgrpix[1] = bgrpix[2] = 0;
		fwrite(&bgrpix,1,pitch,F);
	}
	fclose(F);
}

void PgmPicture::loadBMP(const string & name)
{
  string file=name+".bmp";
	struct BMPHead head;
	int i,j,pitch;
	unsigned char bgrpix[3];
	char corrpitch[4] = {0,3,2,1};
	FILE* F = fopen(file.c_str(),"rb");
	if (!F)
	{
          cout << "error : file " << file << " do not exist" << endl;
          exit(-1);
        }
	fread(&head,sizeof(struct BMPHead),1,F);
	if (head.signature[0]!='B' || head.signature[1]!='M')
		exit(-2) ;  // mauvaise signature, ou BMP non supporté.
	if (head.imhead.bpp!=24)
		exit(-3) ;  // supporte que le 24 bits pour l'instant
	if (head.imhead.compression!=0)
		exit(-4) ;  // rarrissime, je ne sais même pas si un logiciel écrit/lit des BMP compressés. 
	if (head.imhead.cpalette!=0 || head.imhead.cIpalette!=0)
		exit(-5) ; // pas de palette supportée, cependant, a bpp 24, il n'y a pas de palette.
  width = head.imhead.width ;
  height = head.imhead.height ;
  pixels.resize(head.imhead.height*head.imhead.width);

	pitch = corrpitch[(3*head.imhead.width)%4];
	for(j=height;j>=0;j--)
	{
		for(i=0;i<width;i++)
		{
			fread(&bgrpix,1,3,F);
			pixels[j*width+i].r = bgrpix[2];
			pixels[j*width+i].g = bgrpix[1];
			pixels[j*width+i].b = bgrpix[0];
		}
		fread(&bgrpix,1,pitch,F);
	}
	fclose(F);
}