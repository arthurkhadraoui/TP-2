#ifndef MAGASIN_H
#define MAGASIN_H
#include <vector>

namespace vente{
	class Magasin {
	private:
		std::vector<Product*> m_products;
		std::vector<Client*> m_clients;
		std::vector<Order*> m_orders;
	public:
		Magasin();

	}
}



#endif