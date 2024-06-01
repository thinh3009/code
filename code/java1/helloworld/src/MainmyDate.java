public class MainmyDate {
    public static void main(String[] args) {
        //int d;
        myDate md = new myDate(25, 2, 2022);
        System.out.println("day= "+md.GetDay());
        // md.printDay();
        // md.printMonth();
        // md.printYear();
        md.setDay(21);
        System.out.println("day= "+md.GetDay());
        myDate md2= new myDate(30, 9, 2002);
        System.out.println("day="+md2.GetDay());
        md2.setMonth(10);
        System.out.println("month="+md2.getMonth());
    }
}
