public class SapXepCheninterface implements SapXepinterface{

    @Override
    public void sapxeptang(double[] arr) {
        // TODO Auto-generated method stub
        int n=arr.length;
        double key;
        int i ,j;
        for(i=1;i<n;i++){
            key=arr[i];
            j=i-1;
            //di chuyen gia tri lon ve sau
            while(j>=0&& arr[i]>key){
                arr[j+1] =arr[j];
                j=j-1;
            }
            arr[j+1]=key;
        }
    }

    @Override
    public void sapxepgiam(double[] arr) {
        // TODO Auto-generated method stub
        int n=arr.length;
        double key;
        int i ,j;
        for(i=1;i<n;i++){
            key=arr[i];
            j=i-1;
            //di chuyen gia tri lon ve sau
            while(j>=0&& arr[i]<key){
                arr[j+1] =arr[j];
                j=j-1;
            }
            arr[j+1]=key;
        }
    }
    
}
