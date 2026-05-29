def add(a, b):
    """Add two numbers together."""
    return a + b


def multiply(a, b):
    """Multiply two numbers together."""
    return a * b


def test_add():
    """Test the add function."""
    assert add(2, 3) == 5
    assert add(-1, 1) == 0
    assert add(0, 0) == 0
    print("test_add passed")


def test_multiply():
    """Test the multiply function."""
    assert multiply(2, 3) == 6
    assert multiply(-1, 5) == -5
    assert multiply(0, 10) == 0
    print("test_multiply passed")


if __name__ == "__main__":
    test_add()
    test_multiply()
    print("All tests passed!")
