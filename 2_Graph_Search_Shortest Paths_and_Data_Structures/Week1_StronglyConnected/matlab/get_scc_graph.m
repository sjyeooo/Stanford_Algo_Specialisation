function DG = get_scc_graph()

scc = readtable('SCC.txt');
scc = renamevars(scc,["Var1","Var2"],["src","dest"]);

%%
DG = digraph(scc.src,scc.dest);

end