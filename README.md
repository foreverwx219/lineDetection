# Description
This is a demo for detecting straight lines in images. The core method is Hough transformation.

The result image will be saved in the folder "build". It only shows the detected straight lines.

# Usage
## Run Directly
cd build

./lineDetection ../imgData/src.JPG

## Cmake and run
cd build

cmake ..

make

./lineDetection ../imgData/src.JPG

## Test your own images
You could use your own images to test this demo. Please use this commond: **./lineDetection your_image_path**.
