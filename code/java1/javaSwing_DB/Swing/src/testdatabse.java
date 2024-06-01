import java.sql.Connection;

public class testdatabse {
    public static void main(String[] args) {
        Connection connection = database.getConnection();
        System.out.println(connection);
    }
}
