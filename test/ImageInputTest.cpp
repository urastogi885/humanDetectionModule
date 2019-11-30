/*@
 *@file ImageInputTest.cpp
 *@author Aruna Baijal and Umang Rastogi
 *@brief Unit test cases for ImageInput
 *@copyright 2019 Aruna Baijal, Umang Rastogi
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <exception>
#include <ImageInput.hpp>
#include <ReaderWriterMock.hpp>

using ::testing::Return;
using ::testing::_;

TEST(imageInput, validFile) {
  /// Instantiate objects for various classes
  ImageInput imageInput;
  ReaderWriterMock* readerMock = new ReaderWriterMock();
  /// Set mock to read images
  imageInput.setReader(readerMock);
  /// Declare file path
  const std::string fileName = "../test/1_Human.jpg";
  /// Read image in file directory
  cv::Mat sampleImage = cv::imread(fileName, 1);
  /// Add mock implementation to check validity of image file path
  std::ifstream infile(fileName);
  if (infile.good()) {
    /// If file path exist then return full mat file
    cv::Mat z = cv::Mat::zeros(720, 1280, CV_8U);
    EXPECT_CALL(*readerMock, read(_)).WillRepeatedly(
      Return(z));
  } else {
      /// If file path does not exist then return empty mat file
      cv::Mat m;
      EXPECT_CALL(*readerMock, read(_)).WillRepeatedly(
        Return(m));
  }

  cv::Mat result = imageInput.readImage(fileName);
  EXPECT_EQ(sampleImage.size(), result.size());
  /// delete mock object
  delete readerMock;
}

TEST(imageInput, invalidFile) {
  /// Instantiate objects for various classes
  ImageInput imageInput;
  ReaderWriterMock* readerMock = new ReaderWriterMock();
  /// Set mock to read images
  imageInput.setReader(readerMock);
  /// Declare file path
  const std::string fileName = "../test/23_Human.jpg";
  /// Add mock implementation to check validity of image file path
  std::ifstream infile(fileName);
  if (infile.good()) {
    /// If file path exist then return full mat file
    cv::Mat z = cv::Mat::zeros(720, 1280, CV_8U);
    EXPECT_CALL(*readerMock, read(_)).WillRepeatedly(
      Return(z));
  } else {
      /// If file path does not exist then return empty mat file
    cv::Mat m;
    EXPECT_CALL(*readerMock, read(_)).WillRepeatedly(
      Return(m));
  }

  try {
    /// try to read image
    cv::Mat result = imageInput.readImage(fileName);
    std::cout << result.rows << " " << result.cols << std::endl;
    FAIL();  // Expected std::invalid file path exception
  }
  catch(std::exception& err) {
    EXPECT_EQ(err.what(), std::string("Invalid File Path"));
  }
  /// delete mock object
  delete readerMock;
}

