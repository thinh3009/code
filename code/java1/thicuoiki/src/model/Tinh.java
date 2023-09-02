
package model;

import java.util.Objects;

public class Tinh {
    private int matinh;
    private String tentinh;
    public Tinh(int matinh,String tentinh){
        this.matinh=matinh;
        this.tentinh=tentinh;
    }

    public int getMatinh() {
        return matinh;
    }

    public void setMatinh(int matinh) {
        this.matinh = matinh;
    }

    public String getTentinh() {
        return tentinh;
    }

    public void setTentinh(String tentinh) {
        this.tentinh = tentinh;
    }

    @Override
    public String toString() {
        return "Tinh{" + "matinh=" + matinh + ", tentinh=" + tentinh + '}';
    }

    /**
     *
     * @return
     */
    @Override
    public int hashCode() {
        return Objects.hash(matinh, tentinh);
    }
//so sanh tinh giong nhau
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        Tinh other =(Tinh) obj;
        return matinh==other.matinh && Objects.equals(tentinh, other.tentinh);
    }
    
    
}
