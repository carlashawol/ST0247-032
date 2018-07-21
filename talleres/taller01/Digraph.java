import java.util.*;
/**
 * Clase abstracta para la implementacion de grafos dirigidos
 */
public class Digraph {
    LinkedList <vertex> la;
    public Digraph(int num) {
        la = new LinkedList <vertex>();
        for(int i=0; i<num; i++){
            crear(i);
        }
    }
    public void crear(int num){
        vertex v = new vertex(num);
        la.add(v);
    }

    public void addArc(int source, int destination){
        la.get(source).addVecino(la.get(destination));
       }


    public int size() {
        return la.size();
}

       public void main (String args[]){
       
       
   }
}
