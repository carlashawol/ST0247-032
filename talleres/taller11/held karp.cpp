double GetMinimumRoute(int startVertex, std::vector<int> Set, Node* root)
{
    printf("%d\n", CountRecursive);
    CountRecursive++;
    if(Set.empty())
    {
        Node node;
        root->Nodes.clear();
        root->Nodes.push_back(node);
        root->Nodes.at(0).Value = Vertices[0];
        root->Nodes.at(0).Selected = true;
        root->CountNodes = 0;
        return AdjancyMatrix[startVertex][0];
    }

    double totalCost = 999999999;

    int selectedIndex = 0;

    for(unsigned int i=0; i<Set.size(); i++)
    {
        Node node;
        node.Selected=false;
        root->Nodes.push_back(node);
        root->Nodes.at(i).Value = Set.at(i);

        int costOfVisitingCurrentNode = AdjancyMatrix[startVertex][Set.at(i)];

        std::vector<int> newSet(Set);
        newSet.erase(newSet.begin()+i);

        int costOfVisitingOtherNodes = GetMinimumRoute(Set.at(i), newSet, &(root->Nodes.at(i)));

        int currentCost = costOfVisitingCurrentNode + costOfVisitingOtherNodes;

        if(totalCost > currentCost)
        {
            totalCost = currentCost;
            selectedIndex = i;
        }
    }
    root->Nodes.at(selectedIndex).Selected = true;

    return totalCost;
}
// taken from: https://stackoverflow.com/questions/34209375/c-implementation-of-held-karp-and-speed
