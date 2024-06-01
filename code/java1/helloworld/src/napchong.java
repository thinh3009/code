public class napchong {
    //cung ten phuong thuc nhung phai khac kieu du lieu
    public int timMin(int a,int b){
        if(a<b){
            return a;
        }
        else{
            return b;
        }
    }

    public double timMin(Double a,Double b){
        if(a<b){
            return a;
        }
        else{
            return b;
        }
    }

    public double tinhTong(double a, double b){
        return a+b;
    }

    public double tinhTong(double[] arr){
        double tong=0;
        for (int i = 0; i < arr.length; i++) {
            tong+=arr[i];
        }
        return tong;
    }
}
