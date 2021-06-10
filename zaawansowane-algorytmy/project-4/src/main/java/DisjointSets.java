public class DisjointSets {
  public DisjointSetsNode[] elements;

  public DisjointSets(int elementsCount) {
    elements = new DisjointSetsNode[elementsCount];
    for(int i = 0; i < elementsCount; i++) {
      makeSet(i);
    }
  }

  public void makeSet(int index) {
    if(elements[index] == null) {
      elements[index] = new DisjointSetsNode();
    }
  }

  public DisjointSetsNode find(int index) {
    DisjointSetsNode root = elements[index];
    while (root.parent != root) {
      root = root.parent;
    }

    DisjointSetsNode it = elements[index];
    while (it.parent != root) {
      DisjointSetsNode previousParent = it.parent;
      it.parent = root;
      it = previousParent;
    }

    return root;
  }

  public void union(int firstIndex, int secondIndex) {
    DisjointSetsNode firstRoot = find(firstIndex), secondRoot = find(secondIndex);
    if (firstRoot == secondRoot) {
      return;
    }

    if(firstRoot.rank < secondRoot.rank) {
      DisjointSetsNode temp = firstRoot;
      firstRoot = secondRoot;
      secondRoot = temp;
    }

    secondRoot.parent = firstRoot;
    if(firstRoot.rank == secondRoot.rank) {
      firstRoot.rank++;
    }
  }

  private static class DisjointSetsNode {
    int rank;
    DisjointSetsNode parent;

    public DisjointSetsNode() {
      this.rank = 0;
      this.parent = this;
    }
  }
}
