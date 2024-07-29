/*
 * Copyright (c) 2020 Daniel Veilleux
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <string.h>
#include <stdio.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/logging/log.h>

//#define HC_SR04 DT_NODELABEL(hc_sr04)

struct sensors_data {
	uint16_t distance1;
	uint16_t distance2;
};

static const struct device *get_hc_sr04_device(void){
	const struct device *dev = DEVICE_DT_GET_ANY(hc_sr04);
	if (dev == NULL){
		printk("\nError: no device \n");
                return NULL;
	}

	if (!device_is_ready(dev)){
                printk("\n Error Device \"%s\" is not ready;"
                        "check the driver initialization logs for errors.\n",
                        dev->name);
                return NULL;
        }

        printk("Found device \"%s\", getting sensor data\n", dev->name);
        return dev;
}

static void get_hc_sr04_sensor_val(const struct device *dev){
	int ret;
	struct sensors_data data;
	struct sensor_value distance;

	sensor_sample_fetch(dev);
	sensor_channel_get(dev, SENSOR_CHAN_DISTANCE, &distance);

	printk("Distance: %d.%03dM\n", distance.val1, (distance.val2 / 1000));
	data.distance1 = distance.val1;
	data.distance2 = distance.val2;

}

int main(void)
{
	int ret;
	const struct device *dev_hc_sr04 = get_hc_sr04_device();

	if (dev_hc_sr04 == NULL){
		printk("Failed to get device: hc_sr04\n");
		return 1;
	}

	while(1){
		get_hc_sr04_sensor_val(dev_hc_sr04);
		k_sleep(K_MSEC(1000));
	}

	return 0;
}
