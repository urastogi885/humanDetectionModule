/*@
 *@file ReaderWriter.hpp
 *@author Aruna Baijal
 *@brief This class controls the actual source implementation of reader
 *@copyright 2019 Aruna Baijal
 */
#ifndef INCLUDE_READERWRITER_HPP_
#define INCLUDE_READERWRITER_HPP_

#include <IReaderWriter.hpp>

class ReaderWriter : public IReaderWriter {
 public:
  /*
   * @param std::String with image path
   * @return cv::Mat image in Mat format
   */
  cv::Mat read(std::String imagePath);
  /*
   * @param cv::Mat original image
   * @param cv::Rect boundary of detected human in image.
   */
  void drawRectangle(cv::Mat image, cv::Rect boundary);
  /*
   * @param cv::Mat image to display.
   */
  void showImage(cv::Mat);
};

#endif  // INCLUDE_READERWRITER_HPP_