<?php
namespace LAM\PDF;
/*
$Id$

  This code is part of LDAP Account Manager (http://www.ldap-account-manager.org/)
  Copyright (C) 2003 - 2006  Michael Duergner
                2017         Roland Gruber

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/**
 * Simple XML parser.
 *
 * @author Michael Duergner
 * @package PDF
 */

/**
 * Simple XML parser.
 *
 * @author Michael Duergner
 * @package PDF
 */
class xmlParser {

	/**	XML parser */
	private $xmlParser;

	/**
	 * Constructor
	 */
	function __construct() {
		$this->xmlParser = xml_parser_create();
		xml_set_object($this->xmlParser, $this);
		xml_parser_set_option($this->xmlParser, XML_OPTION_CASE_FOLDING, 1);
		xml_parser_set_option($this->xmlParser, XML_OPTION_SKIP_WHITE, 1);
	}

	/**
	 * Starts the parsing.
	 *
	 * @param String $filename file name
	 * @return array XML structure
	 */
	function parse($filename) {
		if(file_exists($filename)) {
			$xmlStructure = array();
			$xmlIndex = array();
			$xmlContent =
			xml_parse_into_struct($this->xmlParser, implode("", file($filename)), $xmlStructure, $xmlIndex);
			return array($xmlStructure, $xmlIndex);
		}
		return array();
	}
}
?>