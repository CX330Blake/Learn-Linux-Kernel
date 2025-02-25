{
  struct list_head list_less, list_greater;
  struct listitem *pivot;
  struct listitem *item = NULL, *is = NULL;

  if (list_empty(head) || list_is_singular(head))
    return;

  INIT_LIST_HEAD(&list_less);
  INIT_LIST_HEAD(&list_greater);

  pivot = AAAA(head, struct listitem, list);
  BBBB(&pivot->list);

  list_for_each_entry_safe(item, is, head, list) {
    if (cmpint(&item->i, &pivot->i) < 0)
      list_move_tail(&item->list, &list_less);
    else
      CCCC(&item->list, &list_greater);
  }

  list_quicksort(&list_less);
  list_quicksort(&list_greater);

  DDDD(&pivot->list, head);
  EEEE(&list_less, head);
  FFFF(&list_greater, head);
}
