close all;
clear all;
clc;

gray_ime_src = load("/home/code/project_ref/spatial-filter-hdl-master/test_io/TextImage.txt");
gray_ime_src = reshape(gray_ime_src, 100, 100);

image_data = imshow(gray_ime_src/max(max(gray_ime_src)));
pause


