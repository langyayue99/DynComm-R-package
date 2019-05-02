/*
 * graphInterface.h
 *
 *  Created on: 19/08/2018
 *      Author: poltergeist0
 */

#ifndef GRAPHINTERFACE_H_
#define GRAPHINTERFACE_H_

#include "edge.h"

/**
 * std::multimap<unsigned int, HalfEdge>
 */
typedef std::multimap<typeVertex, HalfEdge> typeLinks;

/**
 * std::multimap<unsigned int, HalfEdge>::iterator
 */
typedef typeLinks::iterator typeLinksIterator;

/**
 * std::multimap<unsigned int, HalfEdge>::const_iterator
 */
typedef typeLinks::const_iterator typeLinksIteratorConst;

typedef std::pair<typeVertex, HalfEdge> typeLinksPair;

/**
 * std::pair<std::multimap<unsigned int, HalfEdge>::iterator, std::multimap<unsigned int, HalfEdge>::iterator >
 */
typedef std::pair<typeLinksIterator, typeLinksIterator > typeLinksRange;

/**
 * std::pair<std::multimap<unsigned int, HalfEdge>::const_iterator, std::multimap<unsigned int, HalfEdge>::const_iterator >
 */
typedef std::pair<typeLinksIteratorConst, typeLinksIteratorConst > typeLinksRangeConst;

typedef std::set<typeVertex> typeVertexList;

typedef const std::set<typeVertex> typeVertexListConst;

/**
 * std::set<typeNode>::iterator
 */
typedef std::set<typeVertex>::iterator typeVertexListIterator;

/**
 * std::set<typeNode>::const_iterator
 */
typedef std::set<typeVertex>::const_iterator typeVertexListIteratorConst;

typedef std::pair<typeVertexListIteratorConst, typeVertexListIteratorConst > typeVertexListRangeConst;

class GraphInterface {
public:
	virtual ~GraphInterface(){}

	virtual typeLinksRangeConst edges()const =0;

	/**
	 * Add an edge
	 *
	 * @param source
	 * @param destination
	 * @param weight Default value is one
	 * @param replace if true and link exists, it replaces the weight, otherwise fails. Default value is false
	 * @return true if added, false if it already exists
	 */
	virtual bool addEdge(const typeVertex & source, const typeVertex & destination, const typeWeight & weight=1.0, const bool & replace=false)=0;

	/**
	 * Add an edge
	 * @param edge
	 * @param replace if true and link exists, it replaces the weight, otherwise fails. Default value is false
	 * @return true if added, false if it already exists
	 */
	virtual bool addEdge(const Edge & edge, const bool & replace=false)=0;

	/**
	 * remove an edge
	 * @param source
	 * @param destination
	 * @return true if the edge existed and was successfully removed
	 */
	virtual bool removeEdge(const typeVertex & source, const typeVertex & destination)=0;

	/**
	 * remove an edge
	 * @param source
	 * @param destination
	 * @return true if the edge existed and was successfully removed
	 */
	virtual bool removeEdge(const Edge & edge)=0;

	/**
	 *
	 * @return all unique nodes in the graph
	 */
	virtual const typeVertexList & getVertices()const =0;

	/**
	 * @return pointers to the first and last neighbor of the node
	 */
	virtual typeLinksRangeConst neighbors(const typeVertex & node)const =0;

	/**
	 *
	 * @param node
	 * @return the number of neighbors of the given node
	 */
	virtual unsigned int neighborsCount(const typeVertex & node)const=0;

	/**
	 *
	 * @return the largest weight of all links in the graph
	 */
	virtual const typeWeight & maxWeight()const =0;

	/**
	 *
	 * @return the sum of the weight of all links in the graph
	 */
	virtual const typeWeight totalWeight()const =0;

	/**
	 *
	 * @param node
	 * @return the weighted degree (sum of weights of the neighbors) of the node
	 */
	virtual typeWeight weighted_degree(const typeVertex & node)const=0;

	/**
	 *
	 * @return a string representation of this graph
	 */
	virtual const std::string toString(const StringFormater & sf=defaultStringFormater)const=0;

};

#endif /* GRAPHINTERFACE_H_ */