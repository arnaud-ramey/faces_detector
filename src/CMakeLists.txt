ADD_EXECUTABLE( texture_sensor texture_sensor.cpp texture_sensor.h)
TARGET_LINK_LIBRARIES( texture_sensor ${OpenCV_LIBS} ${Boost_LIBRARIES})

ADD_EXECUTABLE( color_face_detector color_face_detector.cpp  color_face_detector.h)
TARGET_LINK_LIBRARIES( color_face_detector ${OpenCV_LIBS} ${Boost_LIBRARIES})

ADD_EXECUTABLE( test_opencv_face_detector test_opencv_face_detector.cpp  opencv_face_detector.h)
TARGET_LINK_LIBRARIES( test_opencv_face_detector ${OpenCV_LIBS} ${Boost_LIBRARIES})
