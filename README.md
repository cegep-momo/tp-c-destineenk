Question 1 : C++
Expliquez en détails une fonctionnalité / notion dans le code que ne nous avons pas ou peu vu en cours.

La fonctionnalité que nous n'avons pas vu
en cours, mais que j'ai utilisé dans le code est std::unique_ptr, un pointeur intelligent de la bibliothèque standard C++ (<memory>). Je l'ai utilisé pour mes methodes displayBooksSortedByTitle() et displayBooksSortedByAuthor() pour trier les livres par titre et auteur en ordre alphabétique.

std::unique_ptr gère automatiquement la durée de vie d'un objet alloué dynamiquement. Lorsqu'un unique_ptr est détruit, à la sortie d'une fonction par exemple, l'objet qu'il possède est automatiquement supprimé pour éviter les fuites de mémoire. Le mot unique signifie qu'il ne peut pas être copié, mais peut être déplacé (std::move).

Dans mes fonctions void Library::displayBooksSortedByTitle() et void Library::displayBooksSortedByAuthor(), je trie les livres (books) à l'aide de std::sort. La fonction de comparaison utilisée est une lambda : [](const unique_ptr<Book>& a, const unique_ptr<Book>& b) {
return a->getTitle() < b->getTitle();
}. La lambda reçoit les unique_ptr par référence constante (ce qui évite toute copie) et compare les titres des livres grâce à l'opérateur -> qui permet d'accéder à l'objet Book pointé. C'est la lambda qui effectue la comparaison des titres ou des auteurs, tandis que et unique_ptr garantit une gestion sûre et automatique de la mémoire des objets comparés.

Question 2 : Options de développement possible
Proposez une solution plus adaptée pour la gestion de bibliothèque et faisant appel éventuellement à une technologie autre que le C++, et expliquez comment vous interfaceriez ça avec le C++. Pensez au futur de cette bibliothèque à Alexandrie qui pourrait éventuellement contenir des millions de livres.

Selon moi une solution plus adaptée pour la gestion de bibliothèque serait de mettre en place un backend chargé de gérer la liste des utilisateurs, des livres, ainsi que les emprunts et les retours. Ce backend pourrait utiliser Node.js(JavaScript) avec une base de données MongoDB, qui est adaptée pour manipuler de grandes quantités de données comme plusieurs millions de livres par exemple.

La bibliothèque serait organisée autour de routes et de middlewares. L'utilisateur devrait d'abord se connecter avant de pouvoir emprunter un livre. Le backend retournerait un message d'erreur si le livre demandé n'est pas disponible. Un compte administrateur pourrait effectuer les requêtes (HTTP GET, POST, PATCH et DELETE) afin de gérer les utilisateurs et les livres en français ajouter, modifier ou supprimer selon les besoins.

Les affichages et les tri sresteraientt en C++. En effet, le code C++ actuel pourrait servir de client qui communiquerait avec le backend à l'aide de requêtes envoyées vers l’API du serveur Node.js, tandis que la gestion des données serait confiée au backend.
