#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/types.h>

static LIST_HEAD(birthday_list);

struct birthday
{
	int day;
	int month;
	int year;
	struct list_head list;
};

int birthday_start(void)
{
	printk(KERN_INFO "Loading Module\n");

	struct birthday *person[5];
	int i = 0;
	while(i < 5)
	{
		person[i] = kmalloc(sizeof(*person[i]), GFP_KERNEL);
		person[i] -> day = 16 + i;
		person[i] -> month = 12 - i;
		person[i] -> year = 1995 + 2 * i;
		INIT_LIST_HEAD(&person[i]->list);
	
		list_add_tail(&person[i++]->list, &birthday_list);
	}

	struct birthday *ptr;

	list_for_each_entry(ptr, &birthday_list, list)
	{
	       	printk("year : %d\nmonth : %d\nday :%d\n", ptr->year, ptr->month,ptr->day);

	}

	return 0;
}

void birthday_exit(void)
{
	struct birthday *ptr, *next;

	list_for_each_entry_safe(ptr, next, &birthday_list, list)
	{
		list_del(&ptr->list);
		kfree(ptr);
	}

	printk(KERN_INFO "Removing Module\n");
}

module_init(birthday_start);
module_exit(birthday_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Birthday Module");
MODULE_AUTHOR("LEE");
