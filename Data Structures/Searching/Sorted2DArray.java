import java.util.Arrays;

public class Sorted2DArray {
    public static int[] binary_search(int[][] matrix, int row, int cStart, int cEnd, int target){
        while(cStart<=cEnd){
            int mid=cStart+(cEnd-cStart)/2;
            if(matrix[row][mid]==target){
                return new int[]{row, mid};
            }else if(matrix[row][mid]<target){
                cStart=mid+1;
            }else{
                cEnd=mid-1;
            }
        }
        return new int[]{-1, -1};
    } 
    
    public static int[] search(int[][] matrix, int target){
        int row=matrix.length;
        int col=matrix[0].length;
        if(col==0){
            return new int[]{-1, -1};
        }
        if(row==1){
            return binary_search(matrix, 0, 0, col-1, target);
        }
        int rStart=0, rEnd=row-1, cMid=col/2;
        while(rStart<(rEnd-1)){
            int rMid=rStart+(rEnd-rStart)/2;
            if(matrix[cMid][rMid]==target){
                return new int[]{cMid, rMid};
            }
            if(matrix[cMid][rMid]>target){
                rEnd=rMid;
            }else{
                rStart=rMid;
            }
        }
        
        if(matrix[rStart][cMid]==target){
            return new int[]{rStart, cMid};
        }
        else if(matrix[rEnd][cMid]==target){
            return new int[]{rEnd, cMid};
        }else if(target<=matrix[rStart][cMid-1]){
            return binary_search(matrix, rStart, 0, cMid-1, target);
        }else if(target>=matrix[rStart][cMid+1] && target<=matrix[rStart][col-1]){
            return binary_search(matrix, rStart, cMid+1, col-1, target);
        }else if(target<=matrix[rStart+1][cMid-1]){
            return binary_search(matrix, rStart+1, 0, cMid-1, target);
        }else{
            return binary_search(matrix, rStart+1, cMid+1, col-1, target);
        }
    }
    
    public static void main(String args[]){
        int[][] matrix={
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };
        System.out.println(Arrays.toString(search(matrix, 5)));
    }
}
