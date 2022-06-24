/* kmalloc_vs_vmalloc 
 * The Linux Channel
 * Author: Kiran Kankipati
 * Updated: 23-nov-2016
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/vmalloc.h>
#include <asm/uaccess.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kiran Kankipati");
MODULE_DESCRIPTION("kmalloc vs vmalloc");
MODULE_VERSION("0.1");

unsigned char *kmallocbuf;
unsigned char *vmallocbuf;

#define BUFLEN 1000

static int __init kmalloc_vs_vmalloc_init(void)
{	unsigned long js, je, jdiff;
	int i=0,j=0;
   kmallocbuf = kmalloc( BUFLEN, GFP_KERNEL);
   if(kmallocbuf)
   {	sprintf(kmallocbuf, "This is a test (kmallocbuf)\n");
     	printk("%s", kmallocbuf);
     	
     	js = jiffies;
     	for(j=0;j<100000;j++){ for(i=0;i<BUFLEN;i++) { kmallocbuf[i] = i+j; } }
     	je = jiffies;
     	printk("dummy print kmallocbuf: %02x\n", kmallocbuf[15]);
     	jdiff = je - js;
     	printk("\nEnd Time [%lu] - Start Time [%lu] - Diff [%lu]\n",je,js, jdiff);
   }
   printk("-------------------------------\n");
   
   vmallocbuf = vmalloc(BUFLEN);
   if(vmallocbuf)
   {	sprintf(vmallocbuf, "This is a test (vmallocbuf)\n");
   	printk("%s", vmallocbuf);
   	
   	js = jiffies;
   	for(j=0;j<100000;j++){ for(i=0;i<BUFLEN;i++) { vmallocbuf[i] = i+j; } }
     	je = jiffies;
     	printk("dummy print vmallocbuf: %02x\n", vmallocbuf[15]);
     	jdiff = je - js;
     	printk("\nEnd Time [%lu] - Start Time [%lu] - Diff [%lu]\n",je,js, jdiff);
   }
   return 0;
}


static void __exit kmalloc_vs_vmalloc_exit(void)
{	
   kfree(kmallocbuf);
   vfree(vmallocbuf);
}

module_init(kmalloc_vs_vmalloc_init);
module_exit(kmalloc_vs_vmalloc_exit);
