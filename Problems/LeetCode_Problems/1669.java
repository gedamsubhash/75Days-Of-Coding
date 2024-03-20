class ListNode{
    ListNode next=null;

}
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode t1=list1;
        for(int i=1; i<a; i++){
            t1=t1.next;
        }
        ListNode t2=list1;
        for(int i=0; i<b; i++){
            t2=t2.next;
        }
        t1.next=list2;
        while(t1.next!=null){
            t1=t1.next;
        }
        t1.next=t2.next;
        return list1;
    }
}