# sdk_graphic_proc_hdmi(not distribute yet)
this project is the SDK project created  by petalinux of Xilinx.Showing graphics processing and output to HDMI port in zynq-7000 series chips

developing environment:
Linux OS:ubuntu 16.04
petalinux:2018.2
vivado:2018.1(vivado project not in this repo)

containing following functions:
1: processing graphics through IP cores and be controled by the drivers designed in DRM of linux kernel;
2: output graphics through HDMI ports(controled in user apps);
