/*@
 *@file ReaderWriteMock.hpp
 *@author Aruna Baijal and Umang Rastogi
 *@brief Mock implementation for testing
 *@copyright 2019 Aruna Baijal, Umang Rastogi
 */
#ifndef TEST_READERWRITERMOCK_HPP_
#define TEST_READERWRITERMOCK_HPP_

#include <string>
#include <fstream>
#include <IReaderWriter.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

class ReaderWriterMock : public virtual IReaderWriter {
 public:
  /*
   * @brief Mock method to read image
   * @param std::String with image path
   * @return cv::Mat image in Mat format
   */
  MOCK_METHOD1(read, cv::Mat(std::string imagePath));
   /*
   * @brief Mock method to show image
   * @param cv::Mat original image
   * @param cv::Rect boundary of detected human in image.
   * @return cv::Mat final image
   */
  MOCK_METHOD1(showImage, void(cv::Mat image));
  /*
   * @brief Mock method to draw ractangular boundary on image
   * @param cv::Mat image to display.
   */
  MOCK_METHOD2(drawRectangle, cv::Mat(cv::Mat image, cv::Rect boundary));
};

#endif  // TEST_READERWRITERMOCK_HPP_
