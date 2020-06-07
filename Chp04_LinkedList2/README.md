# Chapter4. 연결 리스트 2

Chapter4 에서는 Chapter3 의 배열을 이용한 List 와 다르게 동적으로 Node 를 생성해 할당해본다.  
ADT 를 아래와 같이 정의한다.  
- void ListInit(List \* plist);
- void LInsert(List \* plist, LData data);
- int LFirst(List \* plist, LData data);
- int LNext(List \* plist, LData \* pdata);
- LData Remove(List \* plist);
- int LCount(List \* plist);
- void SetSortRule(List \* plist, int (\*comp)(LData d1, LData d2));

---

###### 이 챕터에서 느낀 점

뭐 큰 것은 아닐 수 있지만.. 자주 느끼는 것이지만 사용자 입장에서 일관되게 사용할 수 있도록 하는 것은 중요한 듯 하다.  
그리고 Sorting 해서 넣는 것은.. 이 책에 있는 구현은 O(n) 이어서 좋지는 않을 듯..  
그리고 전반적으로 포인터가 나오니 혼동된다..  
