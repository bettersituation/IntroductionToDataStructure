# Chapter4. ���� ����Ʈ 2

Chapter4 ������ Chapter3 �� �迭�� �̿��� List �� �ٸ��� �������� Node �� ������ �Ҵ��غ���.  
ADT �� �Ʒ��� ���� �����Ѵ�.  
- void ListInit(List \* plist);
- void LInsert(List \* plist, LData data);
- int LFirst(List \* plist, LData data);
- int LNext(List \* plist, LData \* pdata);
- LData Remove(List \* plist);
- int LCount(List \* plist);
- void SetSortRule(List \* plist, int (\*comp)(LData d1, LData d2));

---

###### �� é�Ϳ��� ���� ��

�� ū ���� �ƴ� �� ������.. ���� ������ �������� ����� ���忡�� �ϰ��ǰ� ����� �� �ֵ��� �ϴ� ���� �߿��� �� �ϴ�.  
�׸��� Sorting �ؼ� �ִ� ����.. �� å�� �ִ� ������ O(n) �̾ ������ ���� ��..  
�׸��� ���������� �����Ͱ� ������ ȥ���ȴ�..  
