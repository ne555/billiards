/*
 * ReadJPEG.cpp
 *
 *  Created on: 25/11/2015
 *      Author: ubuntu
 */

#include "ReadJPEG.h"


/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
int ReadJPEG(
    std::string const filename,
    std::vector<uint8_t> *image,
    int *width, int *height )
{
	 if( !image ) {
	        return -1;
	    }

	    FILE * const infile = fopen(filename.c_str(), "rb");
	    if( !infile ) {
	        std::cerr
	            << "error opening file "
	            << filename
	            << " : "
	            << strerror(errno)
	            << std::endl;
	        return -2;
	    }

	    struct jpeg_decompress_struct cinfo;
	    struct jpeg_error_mgr jerr;
	    cinfo.err = jpeg_std_error(&jerr);

	    jpeg_create_decompress(&cinfo);

	    jpeg_stdio_src(&cinfo, infile);
	    jpeg_read_header(&cinfo, TRUE);
	    jpeg_calc_output_dimensions(&cinfo);
	    jpeg_start_decompress(&cinfo);

	    if( width )  { *width  = cinfo.output_width;  }
	    if( height ) { *height = cinfo.output_height; }

	    size_t const stride = cinfo.output_width * cinfo.output_components;
	    image->resize(cinfo.output_height * stride);

	    for(size_t i = 0; i < cinfo.output_height;) {
	        uint8_t * const row =  &(*image)[stride * i];
	        i += jpeg_read_scanlines(&cinfo, (unsigned char**)&row, 1);
	    }
	    jpeg_finish_decompress(&cinfo);

	    fclose(infile);
	    return 0;
	}


/*
void ReadJPEG(char *filename,unsigned char **image,int *width, int *height)
{
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr jerr;
  FILE * infile;
  unsigned char **buffer;
  int i,j;

  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_decompress(&cinfo);


  if ((infile = fopen(filename, "rb")) == NULL) {
    printf("Unable to open file %s\n",filename);
    exit(1);
  }

  jpeg_stdio_src(&cinfo, infile);
  jpeg_read_header(&cinfo, TRUE);
  jpeg_calc_output_dimensions(&cinfo);
  jpeg_start_decompress(&cinfo);

  *width = cinfo.output_width;
  *height  = cinfo.output_height;


  *image=(unsigned char*)malloc(cinfo.output_width*cinfo.output_height*cinfo.output_components);

  buffer=(unsigned char **)malloc(1*sizeof(unsigned char **));
  buffer[0]=(unsigned char *)malloc(cinfo.output_width*cinfo.output_components);


  i=0;
  while (cinfo.output_scanline < cinfo.output_height) {
    jpeg_read_scanlines(&cinfo, buffer, 1);

    for(j=0;j<cinfo.output_width*cinfo.output_components;j++)
      {
	(*image)[i]=buffer[0][j];
	i++;
      }

    }

  free(buffer);
  jpeg_finish_decompress(&cinfo);
 // fclose(filename);
  fclose(infile);
}

*/



