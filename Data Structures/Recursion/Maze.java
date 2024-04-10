public class Maze {
    public static void main(String[] args) {
        // System.out.println(count(3,3));
        // print_paths("", 3, 3);
        int[][] maze={
            {0,0,0},
            {0,0,0},
            {0,0,0}
        };
        // paths_restriction("", maze, 0, 0);
        all_paths("", maze, 0, 0, 0);
    }
    public static int count(int r, int c){
        if(r==1 || c==1){
            return 1;
        }
        int left=count(r-1, c);
        int right=count(r, c-1);
        return left+right;
    }
    public static void print_paths(String p, int r, int c){
        if(r==1 && c==1){
            System.out.println(p);
            return;
        }
        if(r>1){
            print_paths(p+'D', r-1, c);
        }
        if(c>1){
            print_paths(p+'R', r, c-1);
        }
    }
    public static void paths_restriction(String p, boolean[][] maze, int r, int c){
        if(r==maze.length-1 && c==maze[0].length-1){
            System.out.println(p);
            return;
        }
        if(!maze[r][c]){
            return;
        }
        if(r<maze.length-1){
            paths_restriction(p+'D', maze, r+1, c);
        }
        if(c<maze[0].length-1){
            paths_restriction(p+'R', maze, r, c+1);
        }
    }
    public static void all_paths(String p, int[][] maze, int r, int c, int counter){
        if(r==maze.length-1 && c==maze[0].length-1){
            maze[r][c]=counter+1;
            System.out.println("\nThe Path is : ");
            for(int i=0; i<maze.length; i++){
                for(int j=0; j<maze[i].length; j++){
                    System.out.print(maze[i][j]+" ");
                }
                System.out.println();
            }
            return;
        }
        if(maze[r][c]!=0){
            return;
        }
        counter++;
        maze[r][c]=counter;
        if(r<maze.length-1){
            all_paths(p+'D', maze, r+1, c, counter);
        }
        if(c<maze[0].length-1){
            all_paths(p+'R', maze, r, c+1, counter);
        }
        if(r>0){
            all_paths(p+'U', maze, r-1, c, counter);
        }
        if(c>0){
            all_paths(p+'L', maze, r, c-1, counter);
        }
        maze[r][c]=0;
    }
}
