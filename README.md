# my_ros_beginner_set

## 0.현재 repo 받기
git clone https://github.com/L0vOJ/my_ros_beginner_set.git
## 1.아두이노 패키지설치 
sudo apt-get install ros-kinetic-rosserial-python
sudo apt-get install ros-kinetic-rosserial-arduino
sudo apt-get install ros-noetic-rosserial
## 2.pc측은 라이브러리 추출 및 삽입 
## 3.아두이노 usb 권한 부여 (자동으로 하는거 찾을 것)
sudo chmod a+rw /dev/serial/by-id/usb-1a86_USB_Serial-if00-port0
## 4.브릿지 생성 
rosrun rosserial_python serial_node.py /dev/serial/by-id/usb-1a86_USB_Serial-if00-port0
## 5.ros client 쏘기
rosrun tutorial_package server_arduino

## bashrc alias 추가 
alias ardu_go='sudo chmod a+rw /dev/serial/by-id/usb-1a86_USB_Serial-if00-port0 && rosrun rosserial_python serial_node.py /dev/serial/by-id/usb-1a86_USB_Serial-if00-port0' 
