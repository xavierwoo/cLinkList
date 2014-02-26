cLinkList
=========

A link list API written in C

You can insert any type of data in the list, but you'd better to insert the same type of data in one list.

All the data inserted to the list should be stored in the heap previously.

Don't free the memory manually after the insertion, the memory will automatically managed by the list.

If your data are structs that contain pointer elements, you may need to write a destruction function.

The destruction function will be delivered to methods CLinkList_delete and CLinkList_destroyLink to tell the list how to free the memory of each data.
