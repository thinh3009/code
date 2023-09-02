CREATE TABLE users
(
    id INT NOT NULL PRIMARY KEY IDENTITY(1,1),
    username varchar(90) NOT NULL,
    email varchar(100) NOT NULL,
    register_date datetime default CURRENT_TIMESTAMP
)


INSERT INTO users 
(username, email)
VALUES
('Bill Gates', 'bill.gates@microsoft.com'),
('Will Smith', 'will@gmail.com'),
('Elon Musk', 'elon.musk@spacex.com'),
('Bob Marley', 'bob.marley@gmail.com'),
('thinh', 'thinh@gmail.com')
GO

select * from users
use myshop