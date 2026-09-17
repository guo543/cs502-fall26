// Type violation in line 7
// Cannot assign to method type

class Test {
    public static String s(int a) {}
    public static void main(String[] args) {
        int a = true;
        String a = "hello";
        boolean b = s(false, "extra arg" + 1);
    }
}