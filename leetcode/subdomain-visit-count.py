# https://leetcode.com/problems/subdomain-visit-count/description/
class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        splitted_domains = []
        for domain in cpdomains:
            splitted_domain = domain.split(' ')
            splitted_domains.append((int(splitted_domain[0]), splitted_domain[1]))
        domain_map = {}
        
        for domain in splitted_domains:
            splitted_domain = domain[1].split('.')
            keys = []
            if len(splitted_domain) == 3:
                keys.append(splitted_domain[2])
                keys.append(splitted_domain[1] + '.' + splitted_domain[2])
                keys.append(splitted_domain[0] + '.' + splitted_domain[1] + '.' + splitted_domain[2])
            else:
                keys.append(splitted_domain[1])
                keys.append(splitted_domain[0] + '.' + splitted_domain[1])
            for key in keys:
                if not domain_map.get(key):
                    domain_map[key] = domain[0]
                else:
                    domain_map[key] = domain[0] + domain_map[key]
        print(domain_map)
        return [str(val) + " " + str(key) for key, val in domain_map.items()]
