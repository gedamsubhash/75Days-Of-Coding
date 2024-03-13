public class BS_Inclusive {
  public static void main(String[] args) {
    // System.out.println("Hello, World!");
    // int a[]={2, 5, 7, 11, 21, 23, 27, 31, 35, 36, 40, 46, 49, 51, 55};
    // int a[]={4,5,6,3,2,1};
    // int a[]={9,1,3,4,5};
    int a[]={2,2,9,2,2,2,2};
    // System.out.println(find_rotated_array(a, 4));
    System.out.println(find_in_rotated_array2(a, 9));
    // System.out.println(peak_element(a));
    // System.out.println(search_in_mountain(a, 6));
    // System.out.println(search(a, 2));
  }
  // public static int search(int arr[], int target){
  //   int i=0, j=0, count=0;
  //   while(true){
  //     if (target>=arr[i] && target<=arr[j]){
  //       return binary_search(arr, i, j, target);
  //     }
  //     i=j+1;
  //     j=(int)Math.pow(2, count);
  //     count++;
  //   }
  // }
  public static int search(int arr[], int target){
    int i=0, j=1;
    while(target>arr[j]){
      i=j+1;
      j=2*i+1;
    }
    return binary_search1(arr, i, j, target);
  }
  public static int binary_search1(int arr[], int i, int j, int target){
    if(i>j){
      return -1;
    }
    int mid=i+(j-i)/2;
    if(target<arr[mid]){
      return binary_search1(arr, i, mid-1, target);
    }
    else if(target>arr[mid]){
      return binary_search1(arr, mid+1, j, target);
    }
    else{
      return mid;
    }
  }
  public static int peak_element(int arr[]){
    int i=0, j=arr.length-1;
    while(i<j){
      int mid=i+(j-i)/2;
      if(arr[mid]>arr[mid+1]){
        j=mid;
      }
      else{
        i=mid+1;
      }
    }
    return i;
  }
  public static int search_in_mountain(int arr[], int target){
    int i=0, j=arr.length-1, ans=-1;
    while(i<j){
      int mid=i+(j-i)/2;
      if(arr[mid]>arr[mid+1]){
        j=mid;
      }else{
        i=mid+1;
      }
    }
    ans=binary_search2(arr, 0, i, target, true);
    if(ans==-1){
      ans=binary_search2(arr, i+1, arr.length-1, target, false);
    }
    return ans;
  }
  public static int binary_search2(int arr[], int i, int j, int target, boolean asc){
    while(i<=j){
      int mid=i+(j-i)/2;
      if(arr[mid]==target){
        return mid;
      }
      if(asc){
        if(target<arr[mid]){
          j=mid-1;
        }else{
          i=mid+1;
        }
      }else{
        if(target>arr[mid]){
          j=mid-1;
        }else{
          i=mid+1;
        }
      }
    }
    return -1;
  }
  public static int find_rotated_array(int arr[], int target){
    int i=0, j=arr.length-1, ans=-1;
    while(i<j){
      int mid=i+(j-i)/2;
      if(arr[i]<arr[mid]){
        if(arr[mid]>arr[mid+1]){
          j=mid;
        }else{
          i=mid+1;
        }
      }else{
        if(arr[mid]<arr[mid-1]){
          j=mid-1;
        }
        else{
          i=mid+1;
        }
      }
    }
    if(target<arr[0]){
      ans=binary_search1(arr, i+1, arr.length-1, target);
    }else{
      System.out.println(i);
      ans=binary_search1(arr, 0, i, target);
    }
    return ans;
  }
  public static int find_in_rotated_array2(int arr[], int target){
    int pivot=helper_duplicates(arr), ans;
    if(pivot!=-1){
      if(target<arr[0]){
        ans=binary_search1(arr, pivot+1, arr.length-1, target);
      }else{
        ans=binary_search1(arr, 0, pivot, target);
      }
    }else{
      ans=-1;
    }
    return ans;
  }
  public static int helper(int arr[]){
    int i=0, j=arr.length-1;
    while(i<=j){
      int mid=i+(j-i)/2;
      if(mid<j && arr[mid]>arr[mid+1]){
        return mid;
      }
      else if(mid>i && arr[mid]<arr[mid-1]){
        return mid-1;
      }
      else if(arr[i]<=arr[mid]){
        i=mid+1;
      }else{
        j=mid-1;
      }
    }
    return -1;
  }
  public static int helper_duplicates(int arr[]){
    int i=0, j=arr.length-1;
    while(i<j){
      int mid=i+(j-i)/2;
      if(mid<j && arr[mid]>arr[mid+1]){
        return mid;
      }
      else if(mid>i && arr[mid]<arr[mid-1]){
        return mid-1;
      }
      else if(arr[mid]==arr[i] && arr[mid]==arr[j]){
        if(arr[mid]==arr[i]){
          return i;
        }
        i++;
        if(arr[mid]==arr[j]){
          return j;
        }
        j--;
      }
      else{
        if(arr[i]<arr[mid] || (arr[mid]==arr[i]) && arr[mid]>arr[j]){
          i=mid+1;
        }else{
          j=mid-1;
        }
      }
    }
    return -1;
  }
}