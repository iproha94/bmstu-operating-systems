struct usb_driver {

	 // указатель на владельца модуля. Используется для ведения счетчика ссылок, чтобы не выгрузить в неподходящий момент. Переменная устанавливатся в макросе THIS_MODULE
	struct module *owner;

	//указатель на имя драйвера должно быть уникальным среди всех usb драйверов в ядре и обычно это тоже самое имя, которое имеет модель драйвера. Это имя можно увидеть в sysfs /sys/bus/usb/drivers/ в том случае, если драйвер загружен в ядро.
	const char *name;

	// указатель на таблицу структур, которые содержат спиcок всех различных типов usb  устройств, которые воспринимает конкретный драйвер. Если струткура не установлена, то функция обратного вызова ??? никогда не будет вызвана.
	const struct usb_device_id *id_table 

	// вызывается ядром, когда оно думает, что имеет ??? которая может обрабатывать этот драйвер. Второй параметр - указатель на поле типа usb_device_id , эту информацию использует USB ядро , чтобы принять решение о соответствии интерфейса, драйвера, ... Если юзб драйвер принимает переданную структуру, то он должен инициализировать устройство и возвращается 0. Иначе если он не может, то возвращается отрицательное значение.
	int (*probe) (struct usb_interface *intf, const struct usb_device_id *id); 

	// указатель на функцию , которая вызывается ядром, когда больше нет необходиомтси в структуре usb_struct_interface или когда драйвер выгружается из юзб ядра. 
	void(*disconnect)(struct usb_interface *inf); 
}