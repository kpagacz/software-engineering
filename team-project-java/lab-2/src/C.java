public class C extends B {
    @Override
    public void throwException() throws GrandParentException {
        throw new ChildException("ChildException");
    }
}
