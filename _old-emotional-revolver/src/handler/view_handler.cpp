#include "view_handler.h"

ViewHandler::ViewHandler()
{
    GameRegistry* registry = GameRegistry::getInstance();
    m_window = registry->getRenderWindow();
    m_level_handler = registry->getLevelHandler();
}

void ViewHandler::handleView()
{
	//m_view.setSize(m_window->getSize().x, m_window->getSize().y);

    int x_base_size = 1024;
    float xy_ratio = (float) m_window->getSize().x / m_window->getSize().y;
    m_view.setSize(x_base_size, x_base_size/xy_ratio);
    m_view.setCenter(m_level_handler->getPlayerEntity()->getCenter());

    m_window->setView(m_view);
}