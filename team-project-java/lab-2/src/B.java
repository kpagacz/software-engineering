public class B extends A{
    @Override
    public void throwException() throws GrandParentException {
        throw new ParentException("Parent exception");
    }
}
