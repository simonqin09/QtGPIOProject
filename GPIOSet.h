#ifndef GPIOSET_H
#define GPIOSET_H
/*****************************************/
#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define POLL_TIMEOUT (3 * 1000) /* 3 seconds */
#define MAX_BUF 64
//int keepgoing = 1;

enum PIN_DIRECTION{
    INPUT_PIN=0,
    OUTPUT_PIN=1
};

enum PIN_VALUE{
    LOW=0,
    HIGH=1
};
/*****************************************/
/* gpio export */
int gpio_export(unsigned int gpio);
/* gpio unexport */
int gpio_unexport(unsigned int gpio);
/* gpio set dir */
int gpio_set_dir(unsigned int gpio, const char *dir);
/* gpio set value */
int gpio_set_value(unsigned int gpio, unsigned int value);
/* gpio get value */
int gpio_get_value(unsigned int gpio, unsigned int *value);
/* gpio set edge */
int gpio_set_edge(unsigned int gpio, const char *edge);
/* gpio fd open */
int gpio_fd_open(unsigned int gpio, unsigned int dir);
/* gpio fd close */
int gpio_fd_close(int fd);
/*// Callback called when SIGINT is sent to the process (Ctrl-C)
void signal_handler(int sig);*/


#endif // GPIOSET_H
