function DG = get_small_graph()

scc = readtable('./matlab/small.txt');
scc = renamevars(scc,["Var1","Var2"],["src","dest"]);

%%
DG = digraph(scc.src,scc.dest);

end