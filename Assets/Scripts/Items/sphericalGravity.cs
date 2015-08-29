using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class sphericalGravity : MonoBehaviour {
	
	public GameObject obj;

	public float effectorDistance;

	public float gravitationPull;

	private float gravCoeff;

	private float getDistance(Vector3 a, Vector3 b){
		Vector3 temp = a - b;
		float dis = Mathf.Sqrt (temp.x*temp.x + temp.y*temp.y);
		if (dis < 0.1f) {
			return 0.1f;
		}
		return dis;
	}

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		gravCoeff = gravitationPull * this.GetComponent<Rigidbody2D> ().mass * obj.GetComponent<Rigidbody2D> ().mass * (1.0f / (getDistance(this.transform.position,obj.transform.position)));
	}

	void FixedUpdate() {
		if (obj.GetComponent<Rigidbody2D>()) {
			obj.GetComponent<Rigidbody2D>().AddForce((this.transform.position - obj.transform.position).normalized * gravCoeff);
		}
	}
}
