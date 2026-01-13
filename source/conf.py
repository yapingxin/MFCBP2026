# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'MFC编程最佳实践(2026版)'
copyright = '2026, 辛亚平'
author = '辛亚平'
release = '2026.01'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = ['recommonmark',
  'sphinx_markdown_tables',
  'sphinx.ext.autosectionlabel',
]

templates_path = ['_templates']
exclude_patterns = []

language = 'zh_CN'

numfig=True
numfig_format = {
    'code-block': 'Listing %s',
    'figure': '图 %s',
    'section': '章节 %s',
    'table': '表 %s',
}

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']
