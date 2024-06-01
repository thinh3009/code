public class thisKey {
    public class student {
        private String name;
        private String id;
        private int age;
        public student(String id){
            //dung this de phan biet thuoc tinh voi tham so
            this.id=id;//id mau tim la thuoc tinh
            this.showMe();
        }
        public student(String name, String id){
            //dung this de phan biet thuoc tinh voi tham so
            //this(id):da goi o tren phai goi dau tien
            this(id);
            this.name=name;
            
        }
        public student(String name, String id,int age){
            //dung this de phan biet thuoc tinh voi tham so
            //this(id):da goi o tren
            this(id,name);
            this.age=age;
            
        }
        public String getName(){
            return name;
        }
        public void setName(String name){
            this.name=name;
        }
        public String getId(){
            return id;
        }
        public void setId(String id){
            this.id=id;
        }
        public int getAge(){
            return age;
        }
        public void setAge(int age){
            this.age=age;
        }
        public void showMe(){
            
        }
    }
}
