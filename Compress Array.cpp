//This function returns a vector of pair(elem,cnt)
//Note :  if you need in sorted order, pass a sorted array instead.

vector< pair<int, int> > CompressArray(int arr[], int n)
{
	vector < pair<int, int> > res;
	for (int i = 0; i < n; i++)
	{
		if (res.size() == 0) res.push_back(make_pair(arr[i], 1));
		else
		{
			if (arr[i] == res[res.size() - 1].first) res[res.size() - 1].second++;
			else res.push_back(make_pair(arr[i], 1));
		}
	}
	return res;
}
