#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/types.h>
#include <linux/ktime.h>
#include <linux/slab.h>

struct head_list {
	struct head_list *next;
	ktime_t start_time;
};
	
MODULE_AUTHOR("Shchirska Tonya");
MODULE_DESCRIPTION("Hello world printing Linux module");
MODULE_LICENSE("Dual BSD/GPL");

static struct head_list *head;

static int repeat = 1;
module_param(repeat, uint, S_IRUGO);
MODULE_PARM_DESC(times, "num of repeats");

static int __init hello_init(void)
{
	uint i = 0;
	struct head_list *this_var, *next_var;
	if(repeat == 0){
		pr_warn("Repeat parameter equals 0 \n");
	}
	else if(repeat >=5 && repeat <= 10){
		pr_warn("Repeat parameter is between 5 and 10 \n");
	}
	BUG_ON(repeat>10);

	this_var = head;

	for(i = 0; i < repeat; i++){
		m=kmalloc(sizeof(struct head_list), GFP_KERNEL);
		if(i == 5){
			m = NULL;
		}
		if(ZERO_OR_NULL_PTR(m)){
			pr_err("Testing debug output");
			while(head != NULL && repeat != 0){
				var = head;
				head = var->next;
				kfree(var);
			}
			BUG_ON(!m);
			return -ENOMEM;
		}
		this_var->start_time = ktime_get();
		pr_info("Hello, world!\n");
		next_var = this_var;
		this_var = m;
	}
	
	if(repeat != 0){
		kfree(next_var->next);
		next_var->next = NULL;
	}
	
	pr_info("Num of repeats: %d\n", repeat);
	return 0;
}

static void __exit hello_exit(void)
{
	struct head_list *tmp_var;
	while(head != NULL && repeat != 0){
		tmp_var = head;
		pr_info("Time of printing: %lld", tmp_var->start_time);
		head = tmp_var->next;
		kfree(tmp_var);
	}
	pr_info("");
}

module_init(hello_init);
module_exit(hello_exit);
