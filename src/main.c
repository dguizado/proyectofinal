
#include <libudev.h>
#include <stdio.h>


	int main()
{

  struct udev* udev = udev_new();

  enumerate_usb_mass_storage(udev);

  udev_unref(udev);
 
 return 0;

}


