public class CLL {
    private Node head;
    private Node tail;
    CLL(){
        this.head=null;
        this.tail=null;
    }

    public void insertAftertail(int data){
        Node node=new Node(data);
        if(head==null){
            head=node;
            tail=node;
        }else{
            tail.next=node;
            node.next=head;
            tail=tail.next;
        }
    }

    public void printList(){
        Node temp=head;
        do{
            System.out.print(temp.data+" --> ");
            temp=temp.next;
        }while(temp!=head);
        System.out.println(head.data);
    }

    public void deleteNode(int data){
        Node node=findNode(data);
        if(head.data==data){
            tail.next=head.next;
            head=head.next;
        }else if(tail.data==data){
            node.next=head;
            tail=node;
        }else{
            node.next=node.next.next;
        }
    }

    public Node findNode(int data){
        Node temp=head;
        do{
            if(temp.next.data==data){
                return temp;
            }
            temp=temp.next;
        }while(temp!=head);
        return null;
    }

    private class Node{
        private int data;
        private Node next;

        Node(int data){
            this.data=data;
        }
    }
    public static void main(String args[]){
        CLL obj=new CLL();
        obj.insertAftertail(1);
        obj.insertAftertail(2);
        obj.insertAftertail(3);
        obj.insertAftertail(4);
        obj.insertAftertail(5);
        obj.insertAftertail(6);
        obj.deleteNode(2);
        obj.printList();
    }
}
