

 struct udev_device*
get_child(struct udev* udev, struct udev_device* parent, const char* subsystem)
{

   
  udev_device->parent_device = device_new_from_parent(udev_device);
       }
       if (udev_device->parent_device != NULL)
              
			  dbg(udev_device->udev, "returning existing parent %p\n", udev_device->parent_device);

			  return udev_device->parent_device;
    

			  if (!udev_device->driver_set) {

              udev_device->driver_set = 1;

              if (util_get_sys_driver(udev_device->udev, udev_device->syspath, driver, sizeof(driver)) > 0)
                     udev_device->driver = strdup(driver);
       }
       return udev_device->driver;
	  	  
	      
}

static void enumerate_usb_mass_storage(struct udev* udev)
{


struct udev *udev;
    struct udev_enumerate *enumerate;
    struct udev_list_entry *devices, *dev_list_entry;
    struct udev_device *dev;
    
    
    
   
    udev_list_entry_foreach(dev_list_entry, devices) {
        const char *path;
        
   
        path = udev_list_entry_get_name(dev_list_entry);
        dev = udev_device_new_from_syspath(udev, path);

   
   
        dev = udev_device_get_parent_with_subsystem_devtype(
               dev,
               "usb",
               "usb_device");
        if (!dev) {
            exit(1);
        }
    
   
    }
    udev_enumerate_unref(enumerate);

    udev_unref(udev);

    return 0;       
}
    



