ArtPt(v) {
color[v] = gray;
// v initially can only climb up to itself
Low[v] = d[v] = ++time;
for all w in Adj(v) do {
if (color[w] == white) {
pred[w] = v;
ArtPt(w);
// When ArtPt(w) is completed, Low[w] stores the
// lowest value it can climb up for a subtree
// rooted at w.
// Recall v is the parent of w.
if (pred [v] == NULL) {
// v has no predecessor , so v is the root.
// apply observation 1.
if ('w' is v''s second child) output v;
}
else if (Low[w] >= d[v]) output v;
// subtree rooted at w can't climb higher than v
// apply observation 3.
// update Low[v] if a children subtree can
// climb higher
Low[v] = min(Low[v], Low[w]);
}
else if (w != pred[v]) { // (v, w) is a back edge
// update Low[v] if a back edge climbs higher
Low[v] = min(Low[v], d[w]);
}
}
color[v] = black;
}