
#ifndef _IMG_MGR_HPP_
#define _IMG_MGR_HPP_

#include <string>
#include <stdint.h>
#include <memory>
#include <Magick++.h>

typedef struct {
    uint16_t red;
    uint16_t green;
    uint16_t blue;
    uint16_t alpha;
} pixel_t;

///
/// \brief Image manager class
///
/// Wrapper for image wrangling library, in our case libmagick++
/// Provides utilites to open and close image files, and provides 
/// the edge detector class with access to the image data.
///
class ImgMgr
{
    public:
        ImgMgr(char *argv);
        ~ImgMgr();

        unsigned getImgWidth();
        unsigned getImgHeight();
        unsigned getPixelCount();
        pixel_t* getPixelHandle();

        void read_image(const std::string &in_filename);
        void write_image(const std::string &out_filename);

        void test_red_dot(const std::string &out_filename);

    private:
        int m_img_width;
        int m_img_height;
        pixel_t *m_pixels;
};

#endif // _IMG_MGR_HPP_
