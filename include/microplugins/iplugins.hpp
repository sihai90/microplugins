/** \file iplugins.hpp */
#ifndef IPLUGINS_HPP_INCLUDED
#define IPLUGINS_HPP_INCLUDED

#include "iplugin.hpp"

namespace micro {

  /**
    \class iplugins
    \brief Interface for plugins management
    \author Dmitrij Volin
    \date august of 2018 year
    \copyright Boost Software License - Version 1.0

    Kernel's interface.
  */
  template<std::size_t L = MAX_PLUGINS_ARGS>
  class iplugins : public storage<L> {
  protected:

    explicit iplugins(int v, const std::string& nm):storage<L>(v, nm) {}

  public:

    ~iplugins() override {}

    /** \returns Shared pointer to plugins kernel. */
    virtual std::shared_ptr<iplugins<L>> get_shared_ptr() { return nullptr; }

    /** \returns Amount loaded plugins. */
    virtual std::size_t count_plugins() const { return 0; }

    /** \returns Shared pointer to loaded plugin. \param[in] i index of plugin \see count_plugins() */
    virtual std::shared_ptr<iplugin<L>> get_plugin(std::size_t i) { return i ? nullptr : nullptr; }

    /** \returns Shared pointer to loaded plugin or attempts to load it from system. \param[in] nm name of plugin */
    virtual std::shared_ptr<iplugin<L>> get_plugin(const std::string& nm) { return nm.size() ? nullptr : nullptr; }

  };

} // namespace micro

#endif // IPLUGINS_HPP_INCLUDED
