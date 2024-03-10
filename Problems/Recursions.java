import java.util.*;

public class Recursions {
  public static void main(String[] args) {
    // int[] a={4,3,5,1,2,8,6,9,7};
    // merge_sort(a, 0, a.length-1);
    // sort(a, 0, a.length-1);
    // System.out.println(Arrays.toString(a));
    // System.out.println(sub_sequence("abc", ""));
    int a[]={1,2,3};
    System.out.println(itr_subset2(a));
  }
  public static List<List<Integer>> iterative_subset(int arr[]){
    List<List<Integer>> outer=new ArrayList<>();
    outer.add(new ArrayList<>());
    for(int num:arr){
      int n=outer.size();
      for(int i=0; i<n; i++){
        List<Integer> inner=new ArrayList<>(outer.get(i));
        inner.add(num);
        outer.add(inner);
      }
    }
    return outer;
  }
  public static ArrayList<String> sub_sequence(String s, String p){
    if(s==""){
      ArrayList<String> list=new ArrayList();
      list.add(p);
      return list;
    }
    char ch=s.charAt(0);
    ArrayList<String> left=sub_sequence(s.substring(1), p+ch);
    ArrayList<String> right=sub_sequence(s.substring(1), p);
    left.addAll(right);
    return left;
  }
  public static void removeA(String s, String p){
    if(s==""){
      System.out.println(p);
      return ;
    }
    char ch=s.charAt(0);
    if(ch!='a'){
      removeA(s.substring(1), p+ch);
    }
    else{
      removeA(s.substring(1), p);
    }
  }
  public static List<List<Integer>> itr_subset2(int arr[]){
    List<List<Integer>> outerList=new ArrayList<>();
    outerList.add(new ArrayList<>());
    for(int num:arr){
      int n=outerList.size();
      for(int i=0; i<n; i++){
        List<Integer> internalList=new ArrayList<>(outerList.get(i));
        internalList.add(num);
        outerList.add(internalList);
      }
    }
    return outerList;
  }
}